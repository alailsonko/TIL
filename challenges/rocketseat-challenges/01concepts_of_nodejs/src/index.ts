import express, { Request, Response } from 'express';

const app = express();

app.use(express.json());

interface DOTRequestRepository {
  title: string;
  URL: string;
  techs: Array<string>;
}
interface DOTRepositoryId {
  id: string;
}
type DOTRepository = DOTRepositoryId & DOTRequestRepository
const response: Array<DOTRepository> = [];

app.post('/repositories', async (req: Request, res: Response) => {
  try {
    const { title, URL, techs } = await req.body as DOTRequestRepository;

    const repository: DOTRepository = {
      id: `${response.length + 1}`, title, URL, techs,
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
  const repositoryId: string = req.params.id;
  
  delete 
  
});

app.post('/repositories/:id/like', (req: Request, res: Response) => res.json({ message: 'repository post like' }));

app.listen('3333', () => console.log('listening on port 3333'));
