import { FirstProjectPage } from './app.po';

describe('first-project App', () => {
  let page: FirstProjectPage;

  beforeEach(() => {
    page = new FirstProjectPage();
  });

  it('should display message saying app works', () => {
    page.navigateTo();
    expect(page.getParagraphText()).toEqual('app works!');
  });
});
