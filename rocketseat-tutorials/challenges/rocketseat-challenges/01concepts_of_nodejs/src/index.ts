import express, { Request, Response } from 'express';

const app = express();

app.use(express.json());

export interface DOTRequestRepository {
  title: string;
  URL: string;
  techs: Array<string>;
}
export interface DOTRepositoryId {
  id: string;
}
export interface DOTLikes {
  likes: Array<string>;
}
export type DOTRepository = DOTRepositoryId & DOTRequestRepository & DOTLikes
// eslint-disable-next-line prefer-const
let response: Array<DOTRepository> = [];

// eslint-disable-next-line prefer-const

app.post('/repositories', async (req: Request, res: Response) => {
  try {
    const { title, URL, techs } = await req.body as DOTRequestRepository;

    const repository: DOTRepository = {
      id: `${response.length + 1}`, title, URL, techs, likes: [],
    };
    response.push(repository);

    return res.status(201).json(response);
  } catch (err) {
    console.log(err);
    return res.status(401).json(err.message);
  }
});

app.get('/repositories', (req: Request, res: Response) => res.json(response));

app.get('/repositories/:id', (req: Request, res: Response) => {
  try {
    const repositoryId: string = req.params.id;
    const repository = response.filter((item: DOTRepository) => item.id === repositoryId);
    return res.json(repository);
  } catch (err) {
    console.log(err.message);
    return res.status(401).json(err.message);
  }
});

app.delete('/repositories/:id', (req: Request, res: Response) => {
  try {
    const repositoryId: string = req.params.id;
    const repository = response.filter((item: DOTRepository) => item.id !== repositoryId);
    response = repository;
    return res.json(repository);
  } catch (err) {
    return res.status(401).json(err.message);
  }
});

app.post('/repositories/:id/like', (req: Request, res: Response) => {
  try {
    const repositoryId: string = req.params.id;
    const repository = response.filter((item: DOTRepository) => item.id === repositoryId);
    const like = '1';
    repository[0].likes.push(like);
    const repositoryActualized = response.filter((item: DOTRepository) => item.id !== repositoryId);
    response = repositoryActualized;
    response.push(repository[0]);
    return res.json(repository);
  } catch (err) {
    return res.status(401).json(err.message);
  }
});

app.listen('3333', () => console.log('listening on port 3333'));

export default app;
