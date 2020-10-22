import React from 'react';
import { Render } from './custom-render';
import App from './App';
import { screen, waitForElementToBeRemoved } from '@testing-library/react'


describe('<App />', () => {
  it('should renders <App /> component correctly', async () => {
    Render(<App />)
    expect(screen.getByText(/Getting started with React testing library/i)).toBeInTheDocument();
    
    await waitForElementToBeRemoved(() => screen.getByText(/Fetching todos/i))
  });
});