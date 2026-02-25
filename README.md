# 📚 Data Structures in C

---

## 📋 Projektbeschreibung

Dieses Projekt implementiert grundlegende Datenstrukturen in der Programmiersprache C.

### Enthaltene Datenstrukturen

- 🔗 **Singly Linked List** – Einfach verkettete Liste
- 📚 **Dynamic Stack** – Dynamischer Stack auf Basis eines Arrays
- 📥 **Dynamic Queue** – Dynamische Queue (Ringpuffer, FIFO-Prinzip)

---

## 🎯 Ziel des Projekts

Die praktische Umsetzung grundlegender Datenstrukturen unter besonderer Berücksichtigung von:

- ✅ **Zeigerarithmetik** – Pointer-Manipulation und Adressoperationen
- ✅ **Dynamische Speicherverwaltung** – malloc, realloc und free
- ✅ **Modulare Struktur** – Trennung von Header- und Quelldateien
- ✅ **API-Design** – Saubere und klar definierte Funktionsschnittstellen
- ✅ **Testbasierung** – Validierung der Funktionalität durch interne Tests

Die Implementierung legt besonderen Wert auf Speicherstabilität, Robustheit und klar strukturierte Programmierung.

---

## 🛠️ Kompilieren

**Voraussetzung:** GCC (C11)

```
+------------------+---------------------------+
|     Befehl       |       Beschreibung         |
+==================+===========================+
| make             | Projekt kompilieren       |
+------------------+---------------------------+
| ./app            | Programm ausführen        |
+------------------+---------------------------+
| make test        | Tests ausführen           |
+------------------+---------------------------+
| make clean       | Build-Dateien entfernen   |
+------------------+---------------------------+
```

> 💡 Das Projekt wird mit aktivierter Speicherprüfung (`-fsanitize=address`) kompiliert, um Memory-Leaks und ungültige Speicherzugriffe zu erkennen.

---

## 📊 Beispieloutput

```
Queue length: 3
[10, 20, 30]
Dequeue: 10
Dequeue: 20
Queue length after dequeue: 1
[30]

Stack length: 3
[10, 20, 30]
Pop: 30
Pop: 20
Stack length after pop: 1
[10]
```

---

## 📖 Erklärung der Funktionen

---

### 🔴 Singly Linked List (Einfach verkettete Liste)

Die Liste speichert Ganzzahlen (`int`) und verwaltet Speicher dynamisch pro Node.

**Interne Struktur:**
```c
typedef struct Node {
    int value;
    struct Node* next;
} Node;
```

```
+------------------------------------------+---------------------------------------------------------------+
|                Funktion                  |                     Beschreibung                              |
+==========================================+===============================================================+
| list_push_front(head, value)            | Fügt Element am Anfang ein, gibt neuen Kopf zurück            |
+------------------------------------------+---------------------------------------------------------------+
| list_push_back(head, value)             | Fügt Element am Ende ein                                       |
+------------------------------------------+---------------------------------------------------------------+
| list_find(head, value)                  | Sucht nach Wert, gibt Pointer oder NULL zurück               |
+------------------------------------------+---------------------------------------------------------------+
| list_delete(head, value)                | Löscht erstes Vorkommen des Wertes                           |
+------------------------------------------+---------------------------------------------------------------+
| list_length(head)                       | Gibt Anzahl der Elemente zurück                               |
+------------------------------------------+---------------------------------------------------------------+
| list_print(head)                         | Gibt Liste aus: [10, 20, 30]                                 |
+------------------------------------------+---------------------------------------------------------------+
| list_free(head)                         | Gibt gesamten Speicher frei                                  |
+------------------------------------------+---------------------------------------------------------------+
```

---

### 🟠 Dynamischer Stack (Array-basiert)

Der Stack basiert auf einem dynamischen Array und folgt dem LIFO-Prinzip (Last In, First Out).

**Interne Struktur:**
```c
typedef struct Stack {
    int* data;       // Dynamisches Array für die Daten
    size_t size;     // Aktuelle Anzahl der Elemente
    size_t capacity; // Kapazität des Arrays
} Stack;
```

```
+------------------------------------------+---------------------------------------------------------------+
|                Funktion                  |                     Beschreibung                              |
+==========================================+===============================================================+
| stack_new()                             | Initialisiert neuen Stack, reserviert Speicher                |
+------------------------------------------+---------------------------------------------------------------+
| stack_push(stack, value)                | Legt Element oben auf den Stack                               |
+------------------------------------------+---------------------------------------------------------------+
| stack_pop(stack, &value)                | Entfernt oberstes Element, gibt Wert zurück                   |
+------------------------------------------+---------------------------------------------------------------+
| stack_peek(stack, &value)               | Gibt oberstes Element zurück, ohne es zu entfernen            |
+------------------------------------------+---------------------------------------------------------------+
| stack_is_empty(stack)                   | Überprüft, ob Stack leer ist                                 |
+------------------------------------------+---------------------------------------------------------------+
| stack_length(stack)                     | Gibt aktuelle Elementanzahl zurück                           |
+------------------------------------------+---------------------------------------------------------------+
| stack_print(stack)                       | Gibt Stack aus: [10, 20, 30]                                 |
+------------------------------------------+---------------------------------------------------------------+
| stack_free(stack)                       | Gibt gesamten Speicher frei                                  |
+------------------------------------------+---------------------------------------------------------------+
```

---

### 🟢 Dynamische Queue (Ringpuffer, FIFO)

Die Queue basiert auf einem dynamischen Array und folgt dem FIFO-Prinzip (First In, First Out).

Zur effizienten Nutzung des Speichers wird ein Ringpuffer (Circular Buffer) verwendet.

**Interne Struktur:**
```c
typedef struct Queue {
    int* data;       // Dynamisches Array
    size_t size;     // Aktuelle Anzahl der Elemente
    size_t capacity; // Maximale Kapazität
    size_t head;     // Index des ersten Elements
    size_t tail;     // Index für das nächste Einfügen
} Queue;
```

**Ringpuffer-Vorteile:**

```
+----------------------------+---------------------------------------------------------------+
|          Aspekt            |                        Beschreibung                          |
+============================+===============================================================+
| Zeitkomplexität            | O(1) für Enqueue und Dequeue                                  |
+----------------------------+---------------------------------------------------------------+
| Erweiterung               | Automatische Speichererweiterung bei Bedarf                  |
+----------------------------+---------------------------------------------------------------+
| Speichereffizienz         | Optimierte Nutzung des vorhandenen Speicherbereichs          |
+----------------------------+---------------------------------------------------------------+
```

```
+------------------------------------------+---------------------------------------------------------------+
|                Funktion                  |                     Beschreibung                              |
+==========================================+===============================================================+
| queue_new()                             | Initialisiert neue Queue, reserviert Speicher                 |
+------------------------------------------+---------------------------------------------------------------+
| queue_enqueue(queue, value)             | Fügt Element am Ende ein                                     |
+------------------------------------------+---------------------------------------------------------------+
| queue_dequeue(queue, &value)            | Entfernt erstes Element (FIFO), gibt Wert zurück              |
+------------------------------------------+---------------------------------------------------------------+
| queue_peek(queue, &value)               | Gibt erstes Element zurück, ohne es zu entfernen             |
+------------------------------------------+---------------------------------------------------------------+
| queue_is_empty(queue)                   | Überprüft, ob Queue leer ist                                 |
+------------------------------------------+---------------------------------------------------------------+
| queue_length(queue)                     | Gibt Anzahl der Elemente zurück                              |
+------------------------------------------+---------------------------------------------------------------+
| queue_print(queue)                       | Gibt Queue aus: [10, 20, 30]                                |
+------------------------------------------+---------------------------------------------------------------+
| queue_free(queue)                       | Gibt gesamten Speicher frei                                  |
+------------------------------------------+---------------------------------------------------------------+
```

---

## 📁 Projektstruktur

```
data-structures-c/
├── include/
│   ├── list.h        # Header für verkettete Liste
│   ├── stack.h       # Header für Stack
│   └── queue.h       # Header für Queue
├── src/
│   ├── list.c        # Implementierung der Liste
│   ├── stack.c       # Implementierung des Stacks
│   └── queue.c       # Implementierung der Queue
├── tests/
│   ├── test_list.c
│   └── test_queue.c
├── main.c            # Hauptprogramm + Tests
├── Makefile          # Build-Konfiguration
└── README.md         # Diese Datei
```

---

*Viel Erfolg beim Lernen!* 🚀

