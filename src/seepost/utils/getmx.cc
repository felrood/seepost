#include "utils.h"

using namespace std;

string getMX(string &dom) {
	ldns_resolver *res;
	ldns_rdf *domain;
	ldns_pkt *p;
	ldns_rr_list *mx;
	ldns_status s;
	
	p = NULL;
	mx = NULL;
	domain = NULL;
	res = NULL;

	string ret = dom;

	/* create a rdf from the command line arg */
	domain = ldns_dname_new_frm_str(dom.c_str());
	if (!domain) {
		return dom;
	}

	/* create a new resolver from /etc/resolv.conf */
	s = ldns_resolver_new_frm_file(&res, NULL);

	if (s != LDNS_STATUS_OK) {
		exit(EXIT_FAILURE);
	}

	/* use the resolver to send a query for the mx 
	 * records of the domain given on the command line
	 */
	p = ldns_resolver_query(res,
	                        domain,
	                        LDNS_RR_TYPE_MX,
	                        LDNS_RR_CLASS_IN,
	                        LDNS_RD);

	ldns_rdf_deep_free(domain);
	
    if (!p)  {
		return dom;
    }
    
	/* retrieve the MX records from the answer section of that
	 * packet
	 */
	mx = ldns_pkt_rr_list_by_type(p,
	                              LDNS_RR_TYPE_MX,
	                              LDNS_SECTION_ANSWER);
	if (mx) {
		ldns_rr_list_sort(mx);
		
		if(ldns_rr_list_rr_count(mx) != 0) {
			ldns_rr *fstmx = ldns_rr_list_rr(mx, 0);
			ldns_rdf *mmx = ldns_rr_mx_exchange (fstmx);
			ret = string(ldns_rdf2str(mmx));

		}
		ldns_rr_list_deep_free(mx);
	}

    ldns_pkt_free(p);
    ldns_resolver_deep_free(res);
    
    
    if(ret.at(ret.length()-1) == '.') {
    	ret = ret.substr(0, ret.length()-1);
    }
    
    return ret;
}
