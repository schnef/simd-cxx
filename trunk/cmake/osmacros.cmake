IF (WIN32)
        IF(DEBUG)
                SET (DEFINITIONS "-DNDEBUG ")
        ENDIF(DEBUG)
ELSE (WIN32)
        IF(DEBUG)
                SET (DEFINITIONS "-ansi -g -pg -pipe")
        ELSE(DEBUG)
                IF(PEDANTIC)
                        SET (DEFINITIONS "-ansi -g -pg -pipe -Wall -Wstrict-null-sentinel -Weffc++ -Wold-style-cast -pedantic ")
                        SET (DEBUG 1)
                ELSE(PEDANTIC)
                        SET (DEFINITIONS "-DNDEBUG -O3 -pipe ")
                ENDIF(PEDANTIC)
        ENDIF(DEBUG)
ENDIF (WIN32)