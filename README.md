# bitcoinrpc
C language interface to JSON-RPC Bitcoin API.

## To build the shared library
Please make sure that you have all the required dependencies installed.
Then type in the project folder:

    make

to compile a dynamically linked library and put it in `.lib/`. It should
also produce the executable `bin/bitcoinprc_test`.

If you want to clean the directory of compiled files and start from scratch,
use:

    make clean  

### Build dependencies
These dependencies are required, if you want to use the code:

 Library     | Purpose             | Description
 ------------|---------------------|-----------------------------------------
  curl       | send data over HTTP |        
  jansson    | JSON parsing        | tested with >=jansson-2.5
  libuuid    | generate UUIDs      |

To install the build dependencies on Ubuntu, please type the following
command:

    sudo apt-get install libcurl4-openssl-dev libjansson-dev uuid-dev

(or other libcurl4-\*-dev flavour).

## Installation

(not implemented yet)

## Usage
See documentation in [doc/](./doc/README.md) and the header file:
`bitcoinrpc.h`.  Please notice that the code is in the beta stage.


# License
The source code is released under the terms of the MIT license.  Please, see
[LICENSE](./LICENSE) for more information.