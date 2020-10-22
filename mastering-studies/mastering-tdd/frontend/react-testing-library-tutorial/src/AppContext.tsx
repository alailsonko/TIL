import React from 'react';

const initialState = {
    todoList: [],
    activeToDoItem: { id: 0}
}

type InitialStateTypes = {
    todoList: string[],
    activeToDoItem: { id: number}
}

interface ActionTypes {
    type?: string;
    todoList: string[]
    todo: { id: number }
}

export const AppContext = React.createContext<any>({
    appData: initialState,
    appDispatch: {}
});



export const AppProvider: React.FC = ({ children }) => {
   const reducer = (state: InitialStateTypes, action: ActionTypes) => {
       switch (action.type) {
            case "LOAD_TODOLIST":
               return {...state, todoList: action.todoList};
            case "LOAD_SINGLE_TODO":
                return {...state, activeToDoItem: action.todo};
            default:
                return state;
       }
   };
    const [appData, appDispatch] = React.useReducer(reducer, {
        todoList: [],
        activeToDoItem: { id: 0 }
    })
    return (
        <AppContext.Provider value={{ appData, appDispatch }}> 
            {children}
        </AppContext.Provider>
    )
}