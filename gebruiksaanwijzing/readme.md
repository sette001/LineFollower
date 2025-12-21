# Gebruiksaanwijzing

### opladen / vervangen batterijen
De LiIon 18650 batterijen worden opgeladen met behulp van ISDT GO, deze kan veilig de batterijen tot 4.15V brengen. Wanneer de batterijen aan 3V (liever vroeger) zitten zijn ze plat en dienen ze opgeladen te worden, laat ze zeker niet onder de 3V gaan! Nadeel is dat batterijen enkel per één opgeladen kunnen worden en dit een tijdje duurt +- 45 min.

### draadloze communicatie
#### verbinding maken
geen draadloze comm

#### commando's
debug [on/off]  
start  
stop  
set cycle [µs]  
set power [0..255]  
set diff [0..1]  
set kp [0..]  
set ki [0..]  
set kd [0..]  
calibrate black  
calibrate white  

### kalibratie
geen kalibratie

### settings
De robot rijdt stabiel met volgende parameters: 
Power: 60
Kp: 0.085
Kd: 0.027

### start/stop button
Monostabiele pushbutton gesitueerd op de printplaat. bij starten van de microcontroller staat deze in stop modus en zal de ingebouwde led niet branden. De button indrukken zal de linefollower in start modus brengen, te zien aan de ingebouwde led dat brand. Nogmaals op de buton duwen zal deze weer in stop brengen. Spanning kan ten alle tijde onderbroken worden door schakelaar aan de batterijen uit te zetten.
