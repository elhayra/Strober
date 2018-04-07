# Strober

Light your board led with predefined or custom patterns. Strober is a great tool for when you writing Arduino software, and want one of your board leds to operate as an indicator to all kind of situatuions, allowing you quicker debugging and getting info about the board current state.

## Prerequisite
Strober depends on SandTimer library to operate. SandTimer library can be found [here](https://github.com/elhayra/SandTimer). Download and copy it to Arduino libraries folder

## Usage
1. Include Strober.h in your code 
2. Create new Strober instance. e.g.
```
Strober strober;
```

3. Set initial led notes. e.g.
```
void setup()
{
  ...
  strober.setNotes(Strober::Notes::BLINK_SLOW);
  ...
}
```

4. Invoke play() method inside loop(), and set notes in run time according to your needs. e.g.
```
void loop()
{
  strober.play(INDICATOR_LED);
  ...
  ...
  if (x)
    strober.setNotes(Strober::Notes::STROBE);
  else if (y)
    strober.setNotes(Strober::Notes::BLINK_FAST);
}
```

You can also invoke setNotes with a custom made notes array. e.g.
```
int16_t custom_notes[4] = {1, 500, 0, 500};
strober.setNotes(custom_notes, 4);
```
Array size must be even, because each note is a pair i.e. [note, interval], so the array look like so:
(note, interval, note, interval, ..., note, interval)
note value can be 0 or 1, and interval is the time (in milliseconds) to wait before playing next note.
