/* eslint-disable react/jsx-no-duplicate-props */
import React from 'react'

import './styles.css'

// pages
import PageHeader from '../../components/PageHeader'

function TeacherForm() {
  return (
    <div className="container" id="page-teacher-form">
      <PageHeader
        title="Que incrivel que você que dar aulas."
         description="O primeiro passo é preencher esse formulário de inscrição"
        />
        <main>
          <fieldset>
            <legend>
              seus dados
            </legend>

            <div className="input-block">
              <label htmlFor="name">
                Nome Completo
              </label>
              <input
                type="text"
                id="name"
              />
            </div>

            <div className="input-block">
              <label htmlFor="avatar">
                Avatar
              </label>
              <input
                type="text"
                id="avatar"
              />
            </div>

            <div className="input-block">
              <label htmlFor="whatsapp">
                Nome Completo
              </label>
              <input
                type="text"
                id="whatsapp"
              />
            </div>
          </fieldset>
        </main>
    </div>
  )
}

export default TeacherForm;
