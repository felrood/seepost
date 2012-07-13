#include "account.ih"

SEEPost::Account::~Account() {
    delete d_sign_pub;
    delete d_enc_pub;
}

