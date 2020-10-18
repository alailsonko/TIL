import React from 'react';
import { render, screen } from '@testing-library/react';
import App from './App';

// test('renders learn react link', () => {
//   const { getByText } = render(<App />);
//   const linkElement = getByText(/learn react/i);
//   expect(linkElement).toBeInTheDocument();
// });


describe('App component', () => {
   test('should render the app', () => {
     render(<App />);
    // //fails
    //  expect(screen.getByText('Search')).toBeInTheDocument();
    //  // success
    //  expect(screen.getByText('Search:')).toBeInTheDocument();
    //  // success
    //  expect(screen.getByText(/Search/)).toBeInTheDocument();
    expect(screen.getByRole('textbox')).toBeInTheDocument();
  });  
});