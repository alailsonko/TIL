import express, { Request, Response } from 'express';

const app = express();

app.post('/repositories', (req: Request, res: Response) => res.json({ message: 'repository post' }));

app.get('/repositories', (req: Request, res: Response) => res.json({ message: 'repository get' }));

app.get('/repositories/:id', (req: Request, res: Response) => res.json({ message: 'repository get' }));

app.get('/repositories/:id/like', (req: Request, res: Response) => res.json({ message: 'repository get' }));

app.listen('3333', () => console.log('listening on port 3333'));
