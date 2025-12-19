# start/stop interrupt met monostabiele button
<img width="673" height="679" alt="SchemaINTRPT" src="https://github.com/user-attachments/assets/5844de1a-8aa6-40ba-9b95-0592067c3f40" />
DE monostabile knop wordt op een interrupt ingang geplaatst (pin 2,3 bij arduino nano) en langs andere kant verbonden met 5V, met een pull down weerstand wordt floating input vermeden. Wanneer deze knop ingeduwt wordt zal de main loop meteen onderbroken worden aangezien er niet meer aan de start voorwaarde voldaan wordt. Debounce gebeurt met een timer.

