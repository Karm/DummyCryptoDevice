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

## Software

## Path

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



## Certificates
    openssl ecparam -out ca-key.pem -genkey -name prime256v1
    openssl req -x509 -new -key ca-key.pem -out ca-cert.pem
    openssl ecparam -out server-key.pem -genkey -name prime256v1 -noout
    openssl req -new -key server-key.pem -out server-csr.pem
    openssl x509 -req -days 365 -in server-csr.pem -CA ca-cert.pem -CAkey ca-key.pem -set_serial 01 -out server-cert.pem
    openssl dhparam -out dhparam.pem 2048

## Build

    mkdir DummyCryptoDevice-build
    cd DummyCryptoDevice-build
    vcvars32.bat
    cmake ../DummyCryptoDevice -G "NMake Makefiles" -DOPENSSL_LIBRARIES=C:\cygwin64\home\Karm\JWS\openssl-devel-1.0.1e-51.win6.i686\lib\ -DOPENSSL_INCLUDE_DIR=C:\cygwin64\home\Karm\JWS\openssl-devel-1.0.1e-51.win6.i686\include\  -DOPENSSL_ROOT_DIR=C:\cygwin64\home\Karm\JWS\openssl-devel-1.0.1e-51.win6.i686\
    nmake


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
