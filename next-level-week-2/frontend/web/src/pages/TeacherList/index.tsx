import React from 'react';

// styles and icons
import './styles.css';

// components
import PageHeader from '../../components/PageHeader';
import TeacherItem from '../../components/TeacherItem';

function TeacherList() {
  return (
    <div className="container" id="page-teacher-list">
     <PageHeader
        title="Estes são os proffys disponiveis"
     >
       <form action="" id="search-teachers">
          <div className="input-block">
            <label htmlFor="subject">Matérias</label>
            <input type="text" id="subject"/>
          </div>
          <div className="input-block">
            <label htmlFor="week_day">Dia da Semana</label>
            <input type="text" id="week_day"/>
          </div>
          <div className="input-block">
            <label htmlFor="time">Tempo</label>
            <input type="text" id="time"/>
          </div>
       </form>
     </PageHeader>

     <main>
      <TeacherItem />
      <TeacherItem />
      <TeacherItem />
      <TeacherItem />
      <TeacherItem />
     </main>
    </div>
  )
}

export default TeacherList;
