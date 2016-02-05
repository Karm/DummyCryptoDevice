/* Copyright (c) Red Hat Inc., based on e_chil.c
 *
 * ====================================================================
 * Copyright (c) 1999-2001 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    licensing@OpenSSL.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */

#include <stdio.h>
#include <string.h>
#include <openssl/crypto.h>
#include <openssl/pem.h>
#include <openssl/dso.h>
#include <openssl/engine.h>
#include <openssl/ui.h>
#include <openssl/rand.h>
#ifndef OPENSSL_NO_RSA
#include <openssl/rsa.h>
#endif
#ifndef OPENSSL_NO_DH
#include <openssl/dh.h>
#endif
#include <openssl/ecdh.h>
#include <openssl/bn.h>

static int dummy_init(ENGINE *e);
static int dummy_finish(ENGINE *e);

static RSA_METHOD dummy_rsa;
static DH_METHOD dummy_dh;
static const ECDH_METHOD *dummy_ecdh;

/* Constants used when creating the ENGINE */
static const char *engine_dummy_id = "dummy";
static const char *engine_dummy_name = "Dummy hardware engine support";

/* Now, to our own code */

/* This internal function is used by ENGINE_dummy() and possibly by the
 * "dynamic" ENGINE support too */
static int bind_helper(ENGINE *e)
{
    const DH_METHOD *dh;
    const RSA_METHOD *rsa;
    const ECDH_METHOD *ecdh;

    rsa = RSA_get_default_method();
    memcpy(&dummy_rsa, rsa, sizeof dummy_rsa);
    dummy_rsa.name = "Dummy engine RSA method";

    dh = DH_OpenSSL();
    memcpy(&dummy_dh, dh, sizeof dummy_dh);
    dummy_dh.name = "Dummy engine DH method";

    ecdh = ECDH_OpenSSL();
    dummy_ecdh = ecdh;

    if (!ENGINE_set_id(e, engine_dummy_id) ||
        !ENGINE_set_name(e, engine_dummy_name) ||
        !ENGINE_set_DH(e, &dummy_dh) ||
        !ENGINE_set_ECDH(e, dummy_ecdh) ||
        !ENGINE_set_RSA(e, &dummy_rsa) ||
        !ENGINE_set_init_function(e, dummy_init) ||
        !ENGINE_set_finish_function(e, dummy_finish)) {
        return 0;
    }

    return 1;
}

#ifdef OPENSSL_NO_DYNAMIC_ENGINE
static ENGINE *engine_dummy(void)
    {
    ENGINE *ret = ENGINE_new();
    if(!ret)
        return NULL;
    if(!bind_helper(ret))
        {
        ENGINE_free(ret);
        return NULL;
        }
    return ret;
    }

void ENGINE_load_dummy(void)
    {
    /* Copied from eng_[openssl|dyn].c */
    ENGINE *toadd = engine_dummy();
    if(!toadd) return;
    ENGINE_add(toadd);
    ENGINE_free(toadd);
    ERR_clear_error();
    }
#endif

static int dummy_refcount;

/* (de)initialisation functions. */
static int dummy_init(ENGINE *e)
{
    if (dummy_refcount++ != 0) {
        fprintf(stderr, "dummy FAILED: Tried to re-initialise already initialized engine, aborting.\n");
        abort();
    }
    fprintf(stderr, "dummy_init: Refcount now %d\n", dummy_refcount);
    return 1;
}

static int dummy_finish(ENGINE *e)
{
    dummy_refcount--;
    fprintf(stderr, "dummy_finish: Refcount now %d\n", dummy_refcount);
    // abort(); // Where the finish is called...
    return 1;
}

/* This stuff is needed if this ENGINE is being compiled into a self-contained
 * shared-library. */
#ifndef OPENSSL_NO_DYNAMIC_ENGINE
static int bind_fn(ENGINE *e, const char *id)
{
    if(id && (strcmp(id, engine_dummy_id) != 0))
        return 0;
    if(!bind_helper(e))
        return 0;
    return 1;
}
IMPLEMENT_DYNAMIC_CHECK_FN()
IMPLEMENT_DYNAMIC_BIND_FN(bind_fn)
#endif /* OPENSSL_NO_DYNAMIC_ENGINE */

