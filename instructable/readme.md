# Instructable

### stap 1 - bestellen componenten
Bestel alle componenten uit de bill of materials, eventuele reserve componenten zijn aangeraden.

### stap 2 - 3D prints
Stop de .3mf files in een slicer naar keuze en print deze. Deze vormen de basis van de linefollower.

### stap 3 - microcontroller
Wanneer de componenten zijn aangekomen testen we als eerste de microcontroller. Aangezien we met een arduino nano werken hoeven we geen extra libraries te gebruiken. Met het voorbeeldprogramma BLINK kunnen we makkelijk uitesten of de microcontroller werkt en of we er naar kunnen schrijven (arduino nano en juiste COM poort selecteren), moest het schrijven de eerste keer niet lukken kan dit verholpen worden door de reset knop in te drukken.

### stap 4 - testen hardware
Nu de microcontroller getest is kunnen we de rest van de hardware testen. Gebruik hiervoor de "proof of concepts" code en het minimaal elektronisch schema bij elk component. Als deze naar wens werken kunnen we verder naar de vlgende stap.

### stap 5 - in elkaar steken frame
Met werkende componenten kan begonnen worden aan het in elkaar steken van het frame van de linefollower. De motoren komen tussen de motorbevestiging en worden met bouten en moeren vastgehouden (M3), waarna de koppelstukken op de as geshoven kunnen worden en de wielen aan de motoren bevestigd kunnen worden. de HY-S301 module zit vooraan, aan de onderkant met de sensoren naar onder gericht. Deze kan op een paar vaste afstanden gemonteerd worden met M3 bouten.

### stap 6 - voorbereiden printplaat
Nu kan de printplaat voorbereid worden volgens het elektronisch schema, componenten zoals de DRV 8833 en arduino worden met vrouwelijke pinnen met de printplaat verbonden zodat deze verwijderd kunnen worden bij schade/falen van de componenten. De verbindingen met de motoren en de HY-S301 worden ook met connectors gemaakt zodat de printplaat afneembaar is. Als de printplaat klaar is kan deze met M3x10 bouten in het frame gstoken worden.

### stap 7 - aansluiten 
Nu kunnen alle componenen aangesloten worden en de batterijhouders gemonteerd worden. Zorg dat de positive kabel onderbroken word met de schakelaar zodat de batterijspanning ondderbroken kan worden en dat de batterijen in serie staan zodat er minimum 6V geleverd wordt. 

### stap8 - testen
Met alles aangesloten kan de linefollower getest worden, test of de motoren aangestuurd kunnen worden en de sensoren uitgelezen worden. Wanneer het hoofdprogramma in de microcontroller zit kan gestart en gestopt worden met de push button, en de spanning onderbroken worden met de schakelaar. Met behulp van KP, Kd, en power kan de reactie van de linefollower veranderd worden. 



