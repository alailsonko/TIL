import { Router } from 'express';

const routes = Router();

routes.get('/', (req, res) => res.json({ message: 'hello world' }));

export default routes;
