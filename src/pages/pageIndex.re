let component = ReasonReact.statelessComponent("Home");

[@bs.module] external agentLogo : string = "../assets/agent-logo.svg";

[@bs.module] external scriptLogo : string = "../assets/script18-logo.svg";

[@bs.module]
external reasonViennaLogo : string = "../assets/reasonvienna-logo.svg";

[@bs.module] external reactViennaLogo : string = "../assets/React-Vienna.svg";

open Utils;

open Data;

module Link = Gatsby.Link;

module ParallaxScroll = Gatsby.ParallaxScroll;

module Tickets = Tito.Tickets;

let speakerColumn = (speaker: Speaker.t) =>
  <li className="speaker-list--item">
    <SpeakerCard speaker key=speaker.name />
  </li>;

let partnerCard = (partner: Partners.partnerT) =>
  <li className="partner--listItem">
    <a href=partner.href className="partners--logo" title=partner.name>
      <img src=partner.logoUrl alt=partner.name />
    </a>
  </li>;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <ParallaxScroll
        from="top-bottom"
        to_="bottom-top"
        props={
          "--header-ty": {
            "from": "100px",
            "to": "-100px",
          },
        }>
        <header className="teaser">
          <section className="container_centered grid grid-6col">
            <h1 className="teaser--logo">
               <div className="logo"> (s("LINSTAVER.COM")) </div> </h1>
              /* <img src=Assets.logo alt="Linstaver" className="teaser--image" /> */
            <nav className="teaser--navigation">
              <Navigation pathName="/" />
            </nav>
            <p className="teaser--tagline">
              (
                "Linstaver  is and  Investment, Importer and Exporter Company based in Belgium, UK and HK"
                |> s
              )
            </p>
          </section>
        </header>
      </ParallaxScroll>
      <section className="offering">
        <main>
          (
            {js|

### Our Company

Linstaver  is and  Investment, Importer and Exporter Company based in Belgium, UK and HK .
Linstaver was conceived as a response to the challenge of combining profitability with social responsibility in a world where success is increasingly measured by financial attainment; this company seeks to utilise profitability from trade and development to promote growth, whilst successfully contributing to social projects.

### Mission Statement

Profitability achieved through innovative trade and development projects utilising ethical practices while actively supporting charitable initiatives.

#### Services

- **Real Estate**
- **Import/Export**
- **Trading**
- **Investment**

        |js}
            |> md
          )
        </main>
      </section>
      <section className="sponsors">
        <div className="container_centered">
          <h2> ("Partners" |> s) </h2>
          <ul className="partners">
            (
              Partners.partners
              |> Array.map(partnerCard)
              |> ReasonReact.arrayToElement
            )
          </ul>
        </div>
      </section>
    </div>,
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));