import React, { InputHTMLAttributes } from 'react';

import { Container } from './styles';

interface InputProps extends InputHTMLAttributes<HTMLInputElement> {
  name: string;
  icon: React.ComponentType;
}

const Input: React.FC<InputProps> = (props) => (
  <Container>
    <input {...props} />
  </Container>
);

export default Input;
