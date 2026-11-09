# Smart Temperature Monitor — C++

A simple C++ project that simulates a temperature sensor system, like a real embedded system built with Arduino / DHT11 / LM35.

Built by **Ali Mursal Shah** — BS Electronics, COMSATS University Islamabad, 2nd semester.

## What it does

- Reads temperature (simulated sensor)
- Decides the status:
  - `< 25°C` — NORMAL, Fan OFF
  - `25–30°C` — WARM, Fan ON (low speed)
  - `30–35°C` — HOT, Fan ON
  - `> 35°C` — DANGER, Alarm ON
- Shows live readings, fan status, and alarm status

This is the same logic used in real embedded systems — sense → decide → act.

## How to run

```bash
g++ -std=c++17 -o monitor main.cpp
./monitor
```

Then choose:
- `1` — Auto simulation (10 live readings)
- `2` — Manual test (enter your own temperature)

## Demo

Watch the live working video: `demo.mp4`

## What I learned

- C++ functions, conditions, and loops
- How a sensor + controller system works
- How to simulate hardware in software before building it

## Skills

C++, Embedded Systems, Digital Electronics, Git, GitHub
