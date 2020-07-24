import { Router } from 'express';

import AuthenticationUserService from '../services/AuthenticationUserService';

const sessionsRouter = Router();

sessionsRouter.post('/', async (req, res) => {
  try {
    const { email, password } = req.body;

    const authenticationUser = new AuthenticationUserService();

    const { user, token } = await authenticationUser.execute({
      email,
      password,
    });

    delete user.password;

    return res.json({ user, token });
  } catch (err) {
    return res.json(400).json({ error: err.message });
  }
});

export default sessionsRouter;
