#include "accountstore.ih"

SEEPost::AccountStore::AccountStore(string const &dir)

: d_good(false), d_dir(dir), d_accounts(vector<Account*>())

 {
    string pattern(dir + "accounts/*.pkf");

    glob_t pglob;
    
    glob(pattern.c_str(), 0, NULL, &pglob);
    
    size_t i;
    for(i = 0; i < pglob.gl_pathc; i++) {
        Account *a =  new Account(pglob.gl_pathv[i], dir);

        if (a->good()) {
            d_accounts.push_back(a);
        } else {
            globfree(&pglob);
            return;
        }
    }

    globfree(&pglob);
    d_good = true;
}
