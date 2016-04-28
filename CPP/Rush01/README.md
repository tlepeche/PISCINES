
IMonitorModule < acquireData < rendu
	AMonitorModule
		SessionModule   < AText

IMonitorDisplay < rendu
	AMonitorDisplay
		AText < acquireData
			TextNCurses
			TextSmfl
		ACourbe
			CourbeNCurses
			CourbeSfml


gethostname() -> host
getenv("USER") -> user

Note Timo: NetworkModule done, recuperer les octets recus / envoyes, recus / envoyes par secondes, taille maximale et minimale, a actualiser avec un timer a la frequence desiree
