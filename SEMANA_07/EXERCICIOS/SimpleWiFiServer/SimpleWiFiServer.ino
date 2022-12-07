#include <WiFi.h>

const char* ssid     = "Inteli-COLLEGE";
const char* password = "QazWsx@123";

WiFiServer server(80);

const int verde = 47;    
const int azul = 45;
const int amarelo = 35;  

const int verdeAcerto = 0;
const int azulEmpate = 0;
const int amareloAcerto = 0; 

void setup()
{
    Serial.begin(115200);
    pinMode(verde, OUTPUT);      // set the LED pin mode
    pinMode(azul, OUTPUT);
    pinMode(amarelo, OUTPUT);
    
    delay(10);

    digitalWrite(verde, LOW);
    digitalWrite(azul, LOW);
    digitalWrite(amarelo, LOW);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

int value = 0;

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            /*
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");
            */
            //client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            //client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            //client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("<html>");
              client.print("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
                //client.print("<link rel="stylesheet" href=\"style.css\" />");
                client.print("<title>Jogo da Velha</title>");
                client.print("<style type=\"text/css\">");
                  client.print("* {box-sizing: border-box; margin: 0; padding: 0;}");
              
                  client.print("body {height: 100vh; width: 100vw; background-color: rgb(26, 26, 63);}");

                  client.print("h1{width: 100%; text-align: center; position: absolute; margin-top: 100px; color: #FFFFFF; font-size: 50px;font-family: Arial, Helvetica, sans-serif;}");
                  
                  client.print(".board {display: grid; width: 100%; height: 100%; display: grid; justify-content: center; align-content: center; justify-items: center; align-items: center; grid-template-columns: repeat(3, auto);}");
                  
                  client.print(".board.x .cell:not(.x):not(.circle):hover::after,");
                  client.print(".board.x .cell:not(.x):not(.circle):hover::before,");
                  client.print(".board.circle .cell:not(.x):not(.circle):hover::after,");
                  client.print(".board.x .cell:not(.x):not(.circle):hover::before{background: rgba(255, 255, 255, 0.3) !important;}");
                  
                  /* Célula */
                  client.print(".cell {width: 100px; height: 100px; border: 2px solid white; display: flex; justify-content: center; align-items: center; position: relative;}");
                  
                  client.print(".cell.x,");
                  client.print(".cell.circle{cursor: not-allowed;}");
                  
                  client.print(".cell:nth-child(1),");
                  client.print(".cell:nth-child(2),");
                  client.print(".cell:nth-child(3){border-top: none;}");
                  
                  client.print(".cell:nth-child(1),");
                  client.print(".cell:nth-child(4),");
                  client.print(".cell:nth-child(7){border-left: none;}");
                  
                  client.print(".cell:nth-child(7),");
                  client.print(".cell:nth-child(8),");
                  client.print(".cell:nth-child(9){border-bottom: none;}");
                  
                  client.print(".cell:nth-child(3),");
                  client.print(".cell:nth-child(6),");
                  client.print(".cell:nth-child(9){border-right: none;}");
                  
                  /* X */
                  client.print(".cell.x::before,");
                  client.print(".cell.x::after,");
                  client.print(".board.x .cell:not(.x):not(.circle):hover::after,");
                  client.print(".board.x .cell:not(.x):not(.circle):hover::before {content: \"\"; height: calc(100px * 0.15); width: calc(100px * 0.9); background: rgb(2, 116, 59); position: absolute;}");
                  
                  client.print(".cell.x::before,");
                  client.print(".board.x .cell:not(.x):not(.circle):hover::before{transform: rotate(45deg);}");
                  
                  client.print(".cell.x::after,");
                  client.print(".board.x .cell:not(.x):not(.circle):hover::after{transform: rotate(-45deg);}");
                  
                  /* Circle */
                  client.print(".cell.circle::before,");
                  client.print(".cell.circle::after,");
                  client.print(".board.circle .cell:not(.x):not(.circle):hover::after,");
                  client.print(".board.circle .cell:not(.x):not(.circle):hover::after{content: \"\"; height: calc(100px * 0.9); width: calc(100px * 0.9); background: rgb(203, 213, 61); position: absolute; border-radius: 50%;}");
                  
                  /* Mensagem de Vitória */
                  client.print(".winning-message {font-family: Arial, Helvetica, sans-serif; display: none; position: fixed; top: 0; left: 0; right: 0; bottom: 0; justify-content: center; align-items: center; background-color: rgba(0, 0, 0, 0.8); flex-direction: column;}");
                  
                  client.print(".winning-message-button {font-family: Arial, Helvetica, sans-serif; font-size: 2.5rem; background-color: rgb(26, 26, 63); padding: 10px 15px;cursor: pointer; border-radius: 5px; border: none; margin-top: 16px; color: white;}");
                  
                  client.print(".winning-message-button:hover {color: rgb(26, 26, 63); background-color: white;}");
                  
                  client.print(".winning-message-text{color: white; font-size: 5rem;}");
                  
                  client.print(".show-winning-message{display: flex;}");
                client.print("</style>");
              client.print("</head>");
              client.print("<body>");
                client.print("<h1>Jogo da Velha</h1>");
                client.print("<div class=\"board\" data-board>");
                  client.print("<div class=\"cell\" data-cell></div>");
                  client.print("<div class=\"cell\" data-cell></div>");
                  client.print("<div class=\"cell\" data-cell></div>");
                  client.print("<div class=\"cell\" data-cell></div>");
                  client.print("<div class=\"cell\" data-cell></div>");
                  client.print("<div class=\"cell\" data-cell></div>");
                  client.print("<div class=\"cell\" data-cell></div>");
                  client.print("<div class=\"cell\" data-cell></div>");
                  client.print("<div class=\"cell\" data-cell></div>");
                client.print("</div>");
                client.print("<div class=\"winning-message\" data-winning-message>");
                  client.print("<p class=\"winning-message-text\" data-winning-message-text>X Venceu!</p>");
                  client.print("<button class=\"winning-message-button\" data-restart-button>");
                    client.print("Reiniciar!");
                  client.print("</button>");
                client.print("</div>");
                    client.print("<script type=\"text/javascript\">");
                      client.print("const cellElements = document.querySelectorAll(\"[data-cell]\");");
                      client.print("const board = document.querySelector(\"[data-board]\");");
                      client.print("const winningMessageTextElement = document.querySelector(\"[data-winning-message-text]\");");
                      client.print("const winningMessage = document.querySelector(\"[data-winning-message]\");");
                      client.print("const restartButton = document.querySelector(\"[data-restart-button]\");");

                      client.print("let isCircleTurn;");

                      client.print("const winningCombinations = [[0, 1, 2],[3, 4, 5],[6, 7, 8],[0, 3, 6],[1, 4, 7],[2, 5, 8],[0, 4, 8],[2, 4, 6],];");

                      client.print("const startGame = () => {isCircleTurn = false; for (const cell of cellElements) {cell.classList.remove(\"circle\"); cell.classList.remove(\"x\"); cell.removeEventListener(\"click\", handleClick); cell.addEventListener(\"click\", handleClick, { once: true });}");
                        client.print("setBoardHoverClass();");
                        client.print("winningMessage.classList.remove(\"show-winning-message\");};");

                      client.print("const endGame = (isDraw) => {if (isDraw) {winningMessageTextElement.innerText = \"Empate!\";} else {winningMessageTextElement.innerText = isCircleTurn ? \"O Venceu!\" : \"X Venceu!\";} winningMessage.classList.add(\"show-winning-message\");};");

                      client.print("const checkForWin = (currentPlayer) => {return winningCombinations.some((combination) => {return combination.every((index) => {return cellElements[index].classList.contains(currentPlayer);});});};");

                      client.print("const checkForDraw = () => {return [...cellElements].every((cell) => {return cell.classList.contains(\"x\") || cell.classList.contains(\"circle\");});};");

                      client.print("const placeMark = (cell, classToAdd) => {cell.classList.add(classToAdd);};");

                      client.print("const setBoardHoverClass = () => {board.classList.remove(\"circle\"); board.classList.remove(\"x\"); if (isCircleTurn) {board.classList.add(\"circle\");} else {board.classList.add(\"x\");}};");

                      client.print("const swapTurns = () => {isCircleTurn = !isCircleTurn; setBoardHoverClass();};");

                      client.print("const handleClick = (e) => {const cell = e.target;");
                      client.print("const classToAdd = isCircleTurn ? \"circle\" : \"x\"; placeMark(cell, classToAdd);");
                      client.print("const isWin = checkForWin(classToAdd); const isDraw = checkForDraw();");
                      client.print("if (isWin){endGame(false); var wpt = new XMLHttpRequest(); wpt.open(\"GET\", \"/winone\", true); wpt.send();} else if (isDraw) {endGame(true); var wpt = new XMLHttpRequest(); wpt.open(\"GET\", \"/wintwo\", true); wpt.send();} else {swapTurns(); var wpt = new XMLHttpRequest(); wpt.open(\"GET\", \"/winthree\", true); wpt.send();}};");

                      client.print("startGame();");
                      client.print("restartButton.addEventListener(\"click\", startGame);");
                    client.print("</script>");
              client.print("</body>");
            client.print("</html>");
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
        /*
        if(amareloAcerto == 1){
           digitalWrite(verde, HIGH);
        }elseif(azulEmpate == 1){
           digitalWrite(azul, HIGH);
        }else{
           digitalWrite(amarelo, HIGH);
        }
        */
        if (currentLine.endsWith("GET /winone")) {
          digitalWrite(verde, HIGH);
        }
        if (currentLine.endsWith("GET /wintwo")) {
          digitalWrite(azul, HIGH);
        }
        if (currentLine.endsWith("GET /winthree")) {
          digitalWrite(amarelo, HIGH);
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        /*
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(5, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(5, LOW);                // GET /L turns the LED off
        }
        */
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}