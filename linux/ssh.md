# ssh failed public key authencation

1. cat /var/log/secure
*Authentication refused: bad ownership or modes for file .ssh/authorized_keys*
2. chmod 600 .ssh/authorized_keys
