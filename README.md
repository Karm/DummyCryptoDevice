# DummyCryptoDevice
Test dummy engine for SSLCryptoDevice mod_ssl feature. Kudos goes to @notroj

# Linux
Nothing non-standard. dev libs, tool chain, cmake, make

# Windows
## Prerequisites
 * Visual Studio
 * CMake
 * header files and libeay32.lib and ssleay32.lib of your favorite OpenSSL distribution, we use 1.0.1e from Red Hat JBoss Web Server

    ```
    λ ls openssl-devel-1.0.1e-51.win6.i686\include\openssl\
    aes.h       cmac.h      dtls1.h   krb5_asn.h     opensslv.h  rsa.h        tls1.h
    applink.c   cms.h       e_os2.h   kssl.h         ossl_typ.h  safestack.h  ts.h
    asn1.h      comp.h      ebcdic.h  lhash.h        pem.h       seed.h       txt_db.h
    asn1_mac.h  conf.h      ec.h      md2.h          pem2.h      sha.h        ui.h
    asn1t.h     conf_api.h  ecdh.h    md4.h          pkcs12.h    srtp.h       ui_compat.h
    bio.h       crypto.h    ecdsa.h   md5.h          pkcs7.h     ssl.h        whrlpool.h
    blowfish.h  des.h       engine.h  modes.h        pqueue.h    ssl2.h       x509.h
    bn.h        des_old.h   err.h     obj_mac.h      rand.h      ssl23.h      x509_vfy.h
    buffer.h    dh.h        evp.h     objects.h      rc2.h       ssl3.h       x509v3.h
    camellia.h  dsa.h       hmac.h    ocsp.h         rc4.h       stack.h
    cast.h      dso.h       idea.h    opensslconf.h  ripemd.h    symhacks.h
    ```
    ```
    λ ls openssl-devel-1.0.1e-51.win6.i686\lib\
    libeay32.lib  libeay32s.lib  ssleay32.lib  ssleay32s.lib
    ```
    
## Path

For the sake of clarity, here is my Windows PATH at the moment of compilation. Note no CygWin there. Cmder brings a tool or two of its own, like ```ls```, although it is a convenience, not a dependency.

    C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\CommonExtensions\Microsoft\TestWindow;
    C:\Program Files (x86)\MSBuild\14.0\bin;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\BIN;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools;
    C:\Windows\Microsoft.NET\Framework\v4.0.30319;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\VCPackages;
    C:\Program Files (x86)\HTML Help Workshop;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\Team Tools\Performance Tools;
    C:\Program Files (x86)\Windows Kits\10\bin\x86;
    C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.6.1 Tools\;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\CommonExtensions\Microsoft\TestWindow;
    C:\Program Files (x86)\MSBuild\14.0\bin;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\BIN;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools;
    C:\Windows\Microsoft.NET\Framework\v4.0.30319;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\VCPackages;
    C:\Program Files (x86)\HTML Help Workshop;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\Team Tools\Performance Tools;
    C:\Program Files (x86)\Windows Kits\10\bin\x86;
    C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.6.1 Tools\;
    C:\Users\Karm\Downloads\Cmder\bin;
    C:\Program Files\Git\bin;
    C:\Program Files\Git\usr\bin;
    C:\Program Files\Git\share\vim\vim74;
    C:\Users\Karm\Downloads\Cmder\vendor\conemu-maximus5;
    C:\Users\Karm\Downloads\Cmder\vendor\conemu-maximus5\ConEmu;
    C:\ProgramData\Oracle\Java\javapath;
    C:\Windows\system32;
    C:\Windows;
    C:\Windows\System32\Wbem;
    C:\Windows\System32\WindowsPowerShell\v1.0\;
    C:\Program Files (x86)\Windows Kits\10\Windows Performance Toolkit\;
    C:\Program Files\Git\cmd;
    C:\Program Files\Microsoft\Web Platform Installer\;
    C:\Program Files (x86)\CMake\bin;
    C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin;
    C:\Users\Karm\Downloads\Cmder

## Build
    C:\Users\Karm
    λ git clone https://github.com/Karm/DummyCryptoDevice.git
    Cloning into 'DummyCryptoDevice'...
    
    
    C:\Users\Karm
    λ mkdir DummyCryptoDevice-build
    
    
    C:\Users\Karm
    λ cd DummyCryptoDevice-build\
    
    
    C:\Users\Karm\DummyCryptoDevice-build
    λ vcvars32.bat
    
    
    C:\Users\Karm\DummyCryptoDevice-build
    λ cmake ../DummyCryptoDevice -G "NMake Makefiles" -DOPENSSL_LIBRARIES=C:\Users\Karm\openssl-devel-1.0.1e-51.win6.i686\lib\ -DOPENSSL_INCLUDE_DIR=C:\Users\Karm\openssl-devel-1.0.1e-51.win6.i686\include\  -DOPENSSL_ROOT_DIR=C:\Users\Karm\openssl-devel-1.0.1e-51.win6.i686\
    -- The C compiler identification is MSVC 19.0.23506.0
    -- The CXX compiler identification is MSVC 19.0.23506.0
    -- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe
    -- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe -- works
    -- Detecting C compiler ABI info
    -- Detecting C compiler ABI info - done
    -- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe
    -- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe -- works
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Detecting CXX compile features
    -- Detecting CXX compile features - done
    -- Found OpenSSL: C:/Users/Karm/openssl-devel-1.0.1e-51.win6.i686/lib/ssleay32.lib;C:/Users/Karm/openssl-devel-1.0.1e-51.win6.i686/lib/libeay32.lib (found version "1.0.1e")
    -- Configuring done
    -- Generating done
    -- Build files have been written to: C:/Users/Karm/DummyCryptoDevice-build
    
    
    C:\Users\Karm\DummyCryptoDevice-build
    λ nmake
    
    Microsoft (R) Program Maintenance Utility Version 14.00.23506.0
    Copyright (C) Microsoft Corporation.  All rights reserved.
    
    Scanning dependencies of target dummy
    [ 50%] Building C object CMakeFiles/dummy.dir/src/e_dummy.c.obj
    e_dummy.c
    [100%] Linking C shared library lib\dummy.dll
    [100%] Built target dummy

Output artifact: ```C:\Users\Karm\DummyCryptoDevice-build\lib\dummy.dll```

## Certificates
Generating necessary dhparams and certs:

    openssl.exe ecparam -out ca-key.pem -genkey -name prime256v1
    openssl.exe req -x509 -new -key ca-key.pem -out ca-cert.pem
    openssl.exe ecparam -out server-key.pem -genkey -name prime256v1 -noout
    openssl.exe req -new -key server-key.pem -out server-csr.pem
    openssl.exe x509 -req -days 365 -in server-csr.pem -CA ca-cert.pem -CAkey ca-key.pem -set_serial 01 -out server-cert.pem
    openssl.exe dhparam -out dhparam.pem 2048

Eventually ends up with:

    C:\Users\Karm\jws-3.0\certs
    λ ls
    ca-cert.pem  dhparam.pem  server-cert.pem  server-key.pem

## Configuration
mod_ssl configuration:

    <IfModule mod_ssl.c>
    
      Listen localhost:443
      SSLPassPhraseDialog     builtin
      #SSLSessionCache         "shmcb:C:/Users/Karm/jws-3.0/var/cache/httpd/sslcache(512000)"
      SSLSessionCacheTimeout  300
    
      SSLRandomSeed startup   builtin
      SSLRandomSeed connect   builtin
    
      SSLCryptoDevice         dummy
    
      <VirtualHost _default_:443>
        ServerName localhost:443
        ErrorLog logs/ssl_error_log
        TransferLog logs/ssl_access_log
        LogLevel debug
        SSLEngine               on
        SSLProtocol             all -SSLv2 -SSLv3
        SSLCipherSuite          ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES256-GCM-SHA384:DHE-RSA-AES128-GCM-SHA256:DHE-DSS-AES128-GCM-SHA256:kEDH+AESGCM:ECDHE-RSA-AES128-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:DHE-RSA-AES128-SHA256:DHE-RSA-AES128-SHA:DHE-DSS-AES128-SHA256:DHE-RSA-AES256-SHA256:DHE-DSS-AES256-SHA:DHE-RSA-AES256-SHA:AES128-GCM-SHA256:AES256-GCM-SHA384:AES128-SHA256:AES256-SHA256:AES128-SHA:AES256-SHA:AES:CAMELLIA:DES-CBC3-SHA:!aNULL:!eNULL:!EXPORT:!DES:!RC4:!MD5:!PSK:!aECDH:!EDH-DSS-DES-CBC3-SHA:!EDH-RSA-DES-CBC3-SHA:!KRB5-DES-CBC3-SHA
        SSLHonorCipherOrder     on
        SSLOpenSSLConfCmd DHParameters  "C:/Users/Karm/jws-3.0/certs/dhparam.pem"
        SSLCertificateFile              "C:/Users/Karm/jws-3.0/certs/server-cert.pem"
        SSLCertificateKeyFile           "C:/Users/Karm/jws-3.0/certs/server-key.pem"
        SSLCACertificateFile            "C:/Users/Karm/jws-3.0/certs/ca-cert.pem"
      </VirtualHost>
    </IfModule>
