import React from 'react'
import axios from 'axios'
import { Render, screen, waitForElementToBeRemoved } from './custom-render'
import { useParams, MemoryRouter } from 'react-router-dom'
import TodoItem from './TodoItem'

describe('<TodoItem />', () => {
    it("Renders <TodoItem /> correctly for a completed item", async () => {
        useParams.mockReturnValue({ id: 1 });
        Render(<TodoItem />);
    
        await waitForElementToBeRemoved(() =>
          screen.getByText(/Fetching todo item 1/i)
        );
    
        expect(axios.get).toHaveBeenCalledTimes(1);
        expect(screen.getByText(/todo item 1/)).toBeInTheDocument();
        expect(screen.getByText(/Added by: 1/)).toBeInTheDocument();
        expect(
          screen.getByText(/This item has been completed/)
        ).toBeInTheDocument();
      });
});