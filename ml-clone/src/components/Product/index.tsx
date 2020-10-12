import React from "react";

import tshirtImage from "../../assets/tshirt.png";

import SellerInfo from "../SellerInfo";
import ProductAction from "../ProductAction";
import {
  Container,
  Row,
  Panel,
  Column,
  Galery,
  Section,
  Description,
} from "./styles";

const Product: React.FC = () => (
  <Container>
    <Row>
      <a href="http">Compartilhar</a>
      <a href="http">Vender um igual</a>
    </Row>

    <Panel>
      <Column>
        <Galery>
          <img src={tshirtImage} alt="T-Shirt" />
        </Galery>

        <Info />
      </Column>

      <Column>
        <ProductAction />
        <SellerInfo />

        <WarrantySection />
        <WarrantySection />
        <WarrantySection />
      </Column>
    </Panel>
  </Container>
);

const WarrantySection: React.FC = () => (
  <Section>
    <h4>Garantia</h4>

    <div>
      <span>
        <p className="title">Compra garantida com o lorem ipsum</p>
        <p className="description">
          Receba o produto que está esperando ou devolvemos o seu dinheiro
        </p>
      </span>
      <span>
        <p className="title">Garantia do vendedor</p>
        <p className="description">sem garantia</p>
      </span>
    </div>

    <a href="http">Saiba mais sobre garantia</a>
  </Section>
);

const Info: React.FC = () => (
  <Description>
    <h2>Descrição</h2>

    <p>
      Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec scelerisque
      porttitor faucibus. Morbi lobortis luctus orci, sit amet scelerisque
      tellus dictum vel. Suspendisse sollicitudin dui lorem, id finibus leo
      consectetur et. Nunc nec porta risus, vitae rhoncus purus. Suspendisse
      potenti. Quisque tincidunt ultrices sapien, nec posuere ex consectetur a.
      Aenean ipsum diam, dictum et viverra ut, semper eu lacus. In urna lorem,
      elementum quis elit sed, ullamcorper porta tellus. Interdum et malesuada
      fames ac ante ipsum primis in faucibus. Morbi sit amet faucibus ipsum.
      Vestibulum convallis leo eget nisl consectetur, a viverra sem malesuada.
      Donec pharetra egestas risus a scelerisque.
      <br />
      <br />
      Itens inclusos: <br />- 1x LED <br />- 1x LED <br />- 1x LED <br />- 1x
      LED <br />- 1x LED <br />
      <br />
      Curabitur ac arcu vel massa gravida dictum. Nullam vitae eros mollis,
      pharetra quam at, volutpat augue. Proin imperdiet turpis at mauris
      interdum, ut commodo metu s mattis. Aenean consectetur congue nisi ac
      rutrum. Duis ru trum sem at tempor placerat. Pellentesque gravida mattis
      lig ula eu pretium. Nam et scelerisque justo. Nam vel ultricies u rna, vel
      lobortis dolor. Donec sollicitudin ante quis sem dig nissim facilisis.
      Donec tincidunt, magna vel semper pellentesq , enim risus varius erat, nec
      mattis justo sapien sit amet justo Nullam feugiat dui quis massa
      vestibulum molestie.
    </p>
  </Description>
);

export default Product;
