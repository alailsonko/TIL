import 'reflect-metadata';
import app from './app';
import '../database';

app.listen(3000, () => {
  console.log('running server');
});
