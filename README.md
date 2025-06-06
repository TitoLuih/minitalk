# 📡 minitalk

> Proyecto de comunicación entre procesos usando señales - 42 Cursus

---

## 🧠 Descripción

**minitalk** es un proyecto de la Escuela 42 cuyo objetivo es implementar una comunicación simple entre dos programas mediante **señales de UNIX**. Se trata de un reto de bajo nivel que requiere entender cómo los procesos pueden enviarse y recibir información sin usar medios tradicionales como sockets o pipes.

---

## ⚙️ Funcionamiento

El proyecto se compone de **dos programas**:

### 🖥️ Servidor

```bash
./server
```

- Muestra su **PID** al ejecutarse.
- Espera señales del cliente.
- Reconstruye y muestra los mensajes recibidos carácter por carácter.

### 💬 Cliente

```bash
./client <PID_DEL_SERVIDOR> "<MENSAJE>"
```

- Envía el mensaje carácter por carácter al servidor.
- Codifica cada bit del carácter usando:
  - `SIGUSR1` para el bit `0`
  - `SIGUSR2` para el bit `1`

---

## 🔄 Ejemplo de uso

```bash
# En una terminal
$ ./server
PID: 12345

# En otra terminal
$ ./client 12345 "Hola Mundo!"
```

**Salida esperada del servidor:**

```
Hola Mundo!
```

---

## 💡 Cómo funciona

Cada carácter se envía bit a bit. El cliente traduce los bits en señales y las envía al servidor.  
El servidor reconstruye el mensaje a partir de estas señales.

```txt
Letra 'A' = 01000001

Cliente:
SIGUSR1 -> 0  
SIGUSR2 -> 1  
...

Servidor:
Recibe 8 señales -> Reconstruye el carácter
```

---

## ✅ Reglas de oro

- Usa `usleep` entre cada señal para asegurar que el servidor tenga tiempo de procesarla.
- Maneja correctamente las señales asincrónicas con `sigaction`.
- Considera el uso de variables `static` para mantener el estado entre llamadas de señal.

---

## 🛠️ Compilación

```bash
make
```

Esto generará los ejecutables `client` y `server`.

