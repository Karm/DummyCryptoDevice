# Linux
## Prerequisites

## Certificates
    openssl ecparam -out ca-key.pem -genkey -name prime256v1
    openssl req -x509 -new -key ca-key.pem -out ca-cert.pem
    openssl ecparam -out server-key.pem -genkey -name prime256v1 -noout
    openssl req -new -key server-key.pem -out server-csr.pem
    openssl x509 -req -days 365 -in server-csr.pem -CA ca-cert.pem -CAkey ca-key.pem -set_serial 01 -out server-cert.pem
    openssl dhparam -out dhparam.pem 2048

## Build
    
    
## Configuration
httpd.conf added content:

    <IfModule mod_ssl.c>
        SSLRandomSeed startup builtin
        SSLRandomSeed connect builtin
        SSLCryptoDevice dummy
        SSLEngine on
        SSLProtocol             all -SSLv2 -SSLv3
        SSLCipherSuite          ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES256-GCM-SHA384:DHE-RSA-AES128-GCM-SHA256:DHE-DSS-AES128-GCM-SHA256:kEDH+AESGCM:ECDHE-RSA-AES128-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:DHE-RSA-AES128-SHA256:DHE-RSA-AES128-SHA:DHE-DSS-AES128-SHA256:DHE-RSA-AES256-SHA256:DHE-DSS-AES256-SHA:DHE-RSA-AES256-SHA:AES128-GCM-SHA256:AES256-GCM-SHA384:AES128-SHA256:AES256-SHA256:AES128-SHA:AES256-SHA:AES:CAMELLIA:DES-CBC3-SHA:!aNULL:!eNULL:!EXPORT:!DES:!RC4:!MD5:!PSK:!aECDH:!EDH-DSS-DES-CBC3-SHA:!EDH-RSA-DES-CBC3-SHA:!KRB5-DES-CBC3-SHA
        SSLHonorCipherOrder     on
        SSLOpenSSLConfCmd DHParameters "/home/mbabacek/JWS/jboss-ews-2.1/httpd/certs/dhparam.pem"
        SSLCertificateFile "/home/mbabacek/JWS/jboss-ews-2.1/httpd/certs/server-cert.pem"
        SSLCertificateKeyFile "/home/mbabacek/JWS/jboss-ews-2.1/httpd/certs/server-key.pem"
        SSLCACertificateFile "/home/mbabacek/JWS/jboss-ews-2.1/httpd/certs/ca-cert.pem"
    </IfModule>

# Windows
## Prerequisites
 * Visual Studio
 * CMake
 * header files and libeay32.lib and ssleay32.lib of your favorite OpenSSL distribution, we use 1.0.1e from Red Hat JBoss Web Server

    λ ls JWS\openssl-devel-1.0.1e-51.win6.i686\include\openssl\
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

    λ ls JWS\openssl-devel-1.0.1e-51.win6.i686\lib\
    libeay32.lib  libeay32s.lib  ssleay32.lib  ssleay32s.lib
    
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
notroj
    mkdir DummyCryptoDevice-build
    cd DummyCryptoDevice-build
    vcvars32.bat
    cmake ../DummyCryptoDevice -G "NMake Makefiles" -DOPENSSL_LIBRARIES=C:\cygwin64\home\Karm\JWS\openssl-devel-1.0.1e-51.win6.i686\lib\ -DOPENSSL_INCLUDE_DIR=C:\cygwin64\home\Karm\JWS\openssl-devel-1.0.1e-51.win6.i686\include\  -DOPENSSL_ROOT_DIR=C:\cygwin64\home\Karm\JWS\openssl-devel-1.0.1e-51.win6.i686\
    nmake


## Certificates
    openssl ecparam -out ca-key.pem -genkey -name prime256v1
    openssl req -x509 -new -key ca-key.pem -out ca-cert.pem
    openssl ecparam -out server-key.pem -genkey -name prime256v1 -noout
    openssl req -new -key server-key.pem -out server-csr.pem
    openssl x509 -req -days 365 -in server-csr.pem -CA ca-cert.pem -CAkey ca-key.pem -set_serial 01 -out server-cert.pem
    openssl dhparam -out dhparam.pem 2048

## Configuration
httpd.conf added content:

    <IfModule mod_ssl.c>
        SSLRandomSeed startup builtin
        SSLRandomSeed connect builtin
        SSLCryptoDevice dummy
        SSLEngine on
        #SSLProtocol all -SSLv2
        #SSLCipherSuite HIGH:!aNULL:!MD5:!EXP
        SSLProtocol             all -SSLv2 -SSLv3
        SSLCipherSuite          ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES256-GCM-SHA384:DHE-RSA-AES128-GCM-SHA256:DHE-DSS-AES128-GCM-SHA256:kEDH+AESGCM:ECDHE-RSA-AES128-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:DHE-RSA-AES128-SHA256:DHE-RSA-AES128-SHA:DHE-DSS-AES128-SHA256:DHE-RSA-AES256-SHA256:DHE-DSS-AES256-SHA:DHE-RSA-AES256-SHA:AES128-GCM-SHA256:AES256-GCM-SHA384:AES128-SHA256:AES256-SHA256:AES128-SHA:AES256-SHA:AES:CAMELLIA:DES-CBC3-SHA:!aNULL:!eNULL:!EXPORT:!DES:!RC4:!MD5:!PSK:!aECDH:!EDH-DSS-DES-CBC3-SHA:!EDH-RSA-DES-CBC3-SHA:!KRB5-DES-CBC3-SHA
        SSLHonorCipherOrder     on
        SSLOpenSSLConfCmd DHParameters "/home/mbabacek/JWS/jboss-ews-2.1/httpd/certs/dhparam.pem"
        SSLCertificateFile "/home/mbabacek/JWS/jboss-ews-2.1/httpd/certs/server-cert.pem"
        SSLCertificateKeyFile "/home/mbabacek/JWS/jboss-ews-2.1/httpd/certs/server-key.pem"
        SSLCACertificateFile "/home/mbabacek/JWS/jboss-ews-2.1/httpd/certs/ca-cert.pem"
    </IfModule>
