# espManager
Com esta biblioteca, você irá fácilmente conectar seu ESP8266 em sua rede WiFi diretamente de seu celular Android.


# Atenção
A biblioteca trava propositalmente o código até que você conecte-se a sua rede. Porque? Em vários projetos, você precisa da conexão com a internet para que o restante do código funcione normalmente.



# Instruções

1-) Baixe e instale a biblioteca.

2-) Abra o arquivo de exemplo (espManager.ino), faça o upload do código ao seu ESP8266 e deixe-o ligado.

*Apartir daqui, seu ESP8266 ficara piscando lentamente, indicando o funcionamento da biblioteca e aguardando os comandos de conexão do aplicativo.*

3-) Ao ligar o ESP8266 com a biblioteca, será criado uma rede "WiFi_Manager" sem senha, conecte-se a ela.

3-) Instale o aplicativo em seu Android. http://www.mediafire.com/file/zozze6j354v7v7p/espManager.apk

4-) Após conectar-se a rede e instalar o aplicativo, clique em REFRESH e aguarde alguns segundos, o aplicativo irá parecer travado até no máximo 10 segundos em caso de erro com a comunicação.

5-) Selecione sua rede na lista disponível, digite a senha e clique em conectar. O ESP8266 começara piscar rapidamente enquanto estabelece a conexão. *Se não houver senha, deixe em branco*

Se a conexão for estabelecida, o ESP8266 irá parar de piscar.

Se a conexão não for estabelecida, o ESP8266 continuara piscando lentamente.


![alt text](http://i.imgur.com/rZc5muP.png)
