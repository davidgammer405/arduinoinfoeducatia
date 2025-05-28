# BIZY

Proiect de irigare automatizată pentru o seră, realizat în cadrul Infoeducatia.

## Descriere

Acest proiect folosește o placă Arduino pentru a monitoriza și controla irigarea unei sere. Scopul principal este de a optimiza consumul de apă și de a automatiza procesul de udare pe baza unor senzori de umiditate.

## Tehnologii folosite

- **Arduino** (limbaj: C++)
- Senzori de umiditate sol
- Releu pentru controlul pompei de apă
- Senzor de temperatura
- Voltmetru
- Monitor LCD
  
## Utilizare

După încărcarea codului și conectarea hardware-ului:
- Senzorul măsoară umiditatea solului.
- Dacă umiditatea scade sub un anumit prag, releul activează pompa pentru udare.
- Procesul se repetă automat.
- Daca detecteaza o cadere de tensiune trimite un SMS la un numar prestabilit
- Lumina controlata prin SMS
- SMS daca temperatura trce de un anumit threshold

**Autor:** [davidgammer405](https://github.com/davidgammer405) Partea de software
           [cristianulala](https://github.com/Cristianulala)   Partea de hardware
