---
title: Switch Map (Solution)
layout: layouts/lesson.njk
---

You can see an implementation of this [here](/applications/basic-counter-with-switch-map/index.html).

```js
import { fromEvent, interval, merge, NEVER } from 'rxjs';
import { switchMap, mapTo, scan } from 'rxjs/operators';
import { setCount, startButton, pauseButton } from './utilities';

const start$ = fromEvent(startButton, 'click').pipe(mapTo(true));
const pause$ = fromEvent(pauseButton, 'click').pipe(mapTo(false));

const counter$ = merge(start$, pause$).pipe(
  switchMap((isRunning) => {
    return isRunning ? interval(1000) : NEVER;
  }),
  scan((count) => count + 1, 0),
);

counter$.subscribe(setCount);
```

There aren't really any major flaws anymore with our counter.
