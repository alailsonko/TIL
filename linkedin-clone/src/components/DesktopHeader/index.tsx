import React from 'react';

import { Container, 
         Wrapper, 
         LinkedInIcon, 
         SearchInput, 
         HomeIcon, 
         NotificationsIcon, 
         ProfileCircle, 
         CaretDownIcon } from './styles';

const DesktopHeader: React.FC = () => {
  return (
    <Container>
      <Wrapper>
        <div className="left">
          <LinkedInIcon />
          <SearchInput placeholder="Pesquisar" />
        </div>
         <div className="right">
           <nav>
             <button className="active">
               <HomeIcon />
               <span>Início</span>
             </button>
             <button className="active">
               <NotificationsIcon />
               <span>Notificações</span>
             </button>
             <button>
               <ProfileCircle src="https://github.com/alailsonko.png" />
                <span>
                  Eu <CaretDownIcon />
                </span>
             </button>
           </nav>
         </div>
      </Wrapper>
    </Container>
  );
};

export default DesktopHeader;
