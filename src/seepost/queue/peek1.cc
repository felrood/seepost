#include "queue.ih"

SEEPost::Blob SEEPost::Queue::peek() {
    return peek(0);
}