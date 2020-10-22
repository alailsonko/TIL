import { todos } from "../makeTodos";

export default {
  get: jest.fn().mockImplementation((url) => {
    switch (url) {
      case "https://jsonplaceholder.typicode.com/todos":
        return Promise.resolve({ data: todos });
      case "https://jsonplaceholder.typicode.com/todos/1":
          return Promise.resolve({
            data: { id: 1, title: "todo item 1", userId: 1, completed: true },
          });
      default:
        throw new Error(`UNMATCHED URL: ${url}`);
    }
  }),
};