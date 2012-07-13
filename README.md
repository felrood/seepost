SEEPost: a secure electronic messaging system
=======

Dirk N. Nederveen & Anton F. Jongsma

Introduction
-------
This is the source code of our bachelor project named SEEPost.


Requirements
-------
gcc >= 4.6  
bobcat >= 2.21      http://bobcat.sourceforge.net/  
botan >= 1.10       http://botan.randombit.net/  
ccbuild >= 1.5.7    http://www.logfish.net/pr/ccbuild/  

Building
-------
For building the client and server program follow these four steps:

> cd src/seepost  
> ccbuild  
> cd ../  
> ccbuild  

And you are done!

Getting it running
-------
In docs/example you can find some example configuration files for a localhost server.
To setup the server:

> ./server -v -f ../docs/example/localhost_server

To open the client:

> ./client -v -f ../docs/example/alice_localhost.skf

and

> ./client -v -f ../docs/example/bob_localhost.skf

To setup your own server use the serverkeygen script in src/ to create a server configuration.
Then run the server. Create some accounts with the clientkeygen script.
Put the .pkf files in the accounts/ directory of your server and restart it.

TODO
-------
These are some things that should be improved in the code

- Replace Blob by a MemoryRegion from botan
- Create account directories in blobstore/ and inqueue/ if needed
- Make the protocol more consistent as described the thesis.
- The SEND syntax is weird
- Merge the client\_functions, server\_functions and seepost library things together
- More documentation

