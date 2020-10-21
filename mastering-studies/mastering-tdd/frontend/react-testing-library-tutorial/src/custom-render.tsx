import React from 'react';
import { render, RenderOptions, RenderResult } from '@testing-library/react'
import { MemoryRouter } from 'react-router-dom'
import { AppProvider } from './AppContext'

const Wrapper: React.FC = ({ children }) => {
return (
    <AppProvider>
        <MemoryRouter>{children}</MemoryRouter>
    </AppProvider>
   )
}

const customRender: RenderResult = (ui: any, options: React.ComponentType) => render(ui, { wrapper: Wrapper, ...options})


// re-export everything
export * from "@testing-library/react"

export { customRender as render }