import { fromEvent } from 'rxjs';

const button = document.getElementById('create-notification');
const notificationMessages = document.getElementById('notification-messages');
let count = 0
const createNotificationElement = () => {
  const element = document.createElement('article');
  element.innerText = `Something happened. ${++count}`;
  fromEvent(element, 'click').subscribe((event) => {
    console.log('Clicked', event);
    element.remove()
  })
  return element;
};

const addMessageToDOM = () => {
  const notification = createNotificationElement();
  notificationMessages.appendChild(notification);
};

/**
 * Your mission:
 *
 * - Use `fromEvent` to create an observable that streams click events.
 * - Subscribe to that observable.
 * - Use `addMessageToDOM` to add a useless message to the DOM whenever the
 *   stream emits a value.
 */


const click$ = fromEvent(button, 'click');
click$.subscribe({
  next: () => {
    addMessageToDOM();
  }
});

