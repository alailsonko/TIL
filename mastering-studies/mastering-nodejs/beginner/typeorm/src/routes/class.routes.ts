import { Router, Request, Response } from 'express';
import { getRepository } from 'typeorm';
import Class from '../entities/Class';

const classRouter = Router();

classRouter.post('/', async (req: Request, res: Response) => {
  try {
    const repo = getRepository(Class);
    const response = await repo.save(req.body);
    return res.status(201).json(response);
  } catch (err) {
    console.log(err);
  }
});

export default classRouter;
