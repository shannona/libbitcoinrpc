/*
   The MIT License (MIT)
   Copyright (c) 2016 Marek Miller

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
   LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
   OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
   WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>

#include <jansson.h>

#include "../src/bitcoinrpc.h"
#include "bitcoinrpc_test.h"


/* Check if can actualy create a new client */
BITCOINRPC_TESTU(method_init)
{
  BITCOINRPC_TESTU_INIT;

  bitcoinrpc_method_t *m = NULL;

  m = bitcoinrpc_method_init(BITCOINRPC_METHOD_HELP);
  BITCOINRPC_ASSERT(m != NULL,
                    "cannot initialise a new method");
  bitcoinrpc_method_free(m);
  m = NULL;

  m = bitcoinrpc_method_init_params(BITCOINRPC_METHOD_HELP, NULL);
  BITCOINRPC_ASSERT(m != NULL,
                    "cannot initialise a new method with params: NULL");
  bitcoinrpc_method_free(m);
  m = NULL;

  json_t *j = json_object();
  m = bitcoinrpc_method_init_params(BITCOINRPC_METHOD_HELP, j);
  BITCOINRPC_ASSERT(m != NULL,
                    "cannot initialise a new method with params: {}");
  bitcoinrpc_method_free(m);
  m = NULL;

  char invalid[1000] = "THI:S IS IN,VALI}D JS{ON DAT\"A: @@@,,@@@,,,}{{,,,";
  j = (json_t *) invalid;
  m = bitcoinrpc_method_init_params(BITCOINRPC_METHOD_HELP, j);
  BITCOINRPC_ASSERT(m == NULL,
                    "bitcoinrpc_method_init_params does not check for invalid json as params");
  m = NULL;

  BITCOINRPC_TESTU_RETURN(0);
}




BITCOINRPC_TESTU(method)
{
  BITCOINRPC_TESTU_INIT;
  BITCOINRPC_RUN_TEST(method_init, o, NULL);
  BITCOINRPC_TESTU_RETURN(0);
}
