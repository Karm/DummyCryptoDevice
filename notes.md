# Certificates
openssl dhparam -out dh_2048.pem 2048

# Configuration
httpd.conf added content:


<IfModule mod_ssl.c>
SSLRandomSeed startup builtin
SSLRandomSeed connect builtin
SSLCryptoDevice dummy
SSLEngine on
SSLProtocol all -SSLv2
SSLCipherSuite HIGH:!aNULL:!MD5:!EXP
SSLCertificateFile "/root/APACHE-2.2.31/logs/newcert.pem"
SSLCertificateKeyFile "/root/APACHE-2.2.31/logs/newkey.pem"
</IfModule>

NOTE: Yes my certifications are in the logs directory but don't ask me one i'm a weird person.
