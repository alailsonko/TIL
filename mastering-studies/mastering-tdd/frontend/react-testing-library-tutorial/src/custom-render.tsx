import React from 'react';
import { MemoryRouter } from 'react-router-dom'
import { AppProvider } from './AppContext'
import { render, RenderOptions, RenderResult } from '@testing-library/react'

const WrapperComponent: React.ComponentType = ({ children }) => {
return (
    <AppProvider>
        <MemoryRouter>{children}</MemoryRouter>
    </AppProvider>
   )
}

export const Render: RenderResult = (ui: React.ReactElement, options: RenderOptions) => render(ui, { wrapper: WrapperComponent, ...options})

// re-export everything
export * from "@testing-library/react"

// export { customRender as Render }

 