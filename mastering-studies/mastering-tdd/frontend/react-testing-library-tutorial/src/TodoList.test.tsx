import React from 'react';
import axios from 'axios';
import { render, screen, waitForElementToBeRemoved } from '@testing-library/react'
import TodoList from './TodoList'
import { todos } from './makeTodos'
import { Render } from './custom-render'

describe('<App />', () => {
    it('Renders <TodoList /> component', async () => {
        Render(<TodoList />)
        await waitForElementToBeRemoved(() => screen.getByText(/Fetching todos/i))
        
        expect(axios.get).toHaveBeenCalledTimes(1)
        todos.slice(0, 15).forEach((td: any) => {
            expect(screen.getByText(td.title)).toBeInTheDocument()
        })
    });
});