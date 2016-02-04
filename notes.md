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

# Windows
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
