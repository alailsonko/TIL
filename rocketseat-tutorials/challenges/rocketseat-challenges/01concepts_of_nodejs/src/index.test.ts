const supertest = require('supertest');
const app = require('./index');

const request = supertest(app);

describe('Name of the group', () => {
  test('should be able to get all repository.', async (done) => {
    const response = await request.get('/repositories');
    expect(response.status).toBe(200);
    done();
  });
});
