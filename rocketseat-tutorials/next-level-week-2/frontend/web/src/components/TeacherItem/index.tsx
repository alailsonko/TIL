import React from 'react';

import whatsappIcon from '../../assets/images/icons/whatsapp.svg'
import './styles.css';


const TeacherItem: React.FC = () => {
  return (
    <article className="teacher-item">
    <header>
      <img
      src="https://avatars2.githubusercontent.com/u/35277996?s=460&u=5e41c5e3a28406ce7e90872e5bde7aded6b00899&v=4"
      alt="profile pic"/>

      <div>
        <strong>Alailson Andrade</strong>
        <span>Quimica</span>
      </div>
    </header>
    <p>
    is simply dummy text of the printing and
    <br/><br/>
    typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
    </p>
    <footer>
      <p>
        Preço/hora
        <strong>R$ 80,00</strong>
      </p>
      <button type="button">
        <img src={whatsappIcon} alt="whatsapp icon"/>
        Entrar em contato
      </button>
    </footer>
  </article>
  )
}


export default TeacherItem;
