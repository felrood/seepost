#include "clientconfig.h"

SEEPost::ClientConfig::~ClientConfig() {
    delete d_sign_priv;
    delete d_enc_priv;
    delete d_sign_pub;
    delete d_enc_pub;
}
