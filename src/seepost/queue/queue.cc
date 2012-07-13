#include "queue.ih"

SEEPost::Queue::Queue(string path)
:
 d_path(path)
{
	struct stat st;
	d_good = ((stat(path.c_str(), &st) == 0) && S_ISDIR(st.st_mode));

	if(!d_good) {
		d_good = (mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0);
	}
	d_good = true;
}