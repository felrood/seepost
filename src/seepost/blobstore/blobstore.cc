#include "blobstore.ih"

SEEPost::BlobStore::BlobStore(string const &dir)
: d_good(true), d_dir(dir)
{
}
