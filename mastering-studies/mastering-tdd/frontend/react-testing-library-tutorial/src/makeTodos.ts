const makeTodos = (n: any) => {
    // returns n number of todo items
    // default is 15
    const num = n || 15;
    const todos = [];
    for (let i = 0; i < num; i++) {
      todos.push({
        id: i,
        userId: i,
        title: `Todo item ${i}`,
        completed: [true, false][Math.floor(Math.random() * 2)],
      });
    }
    return todos;
  };
  
  export const todos = makeTodos(200);