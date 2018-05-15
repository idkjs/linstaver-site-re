[@bs.module] external style : Js.t({..}) = "./about.module.scss";

let component = ReasonReact.statelessComponent("About");

open Utils;

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> ("About Linstaver" |> s) </h1>
      <h2> ("Mission" |> s) </h2>
      <main>
        <p>
          (
            {js|
**About Linstaver**

**Linstaver** company  is a combined by successful professionals with proven experiences and expertises in their field of business in different locations,  who are able to bring not simply a diverse range of products and services but detailed and hands on experience in operating on the different countries, handling its often diverse business cultures.

Linstaver has several decades of professional experience.  Financial transactions are secured thanks to our banking network, in order to optimize our risks management.

* **Our Goal **: Performance and margin optimization represent are our daily focus, to meet our clients expectation. The deep knowledge of the market, and expertise of our partners give us a competitive advantage tomanage risk in the business.

*  **To achieve our target**, we count on a strong Network and partnership around the world.

**Risk Management:**

Our successful experience in service providing a wide variety of  projects and dossiers has enabled us to establish an efficient risk management policy. We monitor on a daily basis the risks associated with this business and our risk committee defines risk limits that Linstaver can take. We identify, we quantify and mitigate the risks constantly and during for each transaction.

Our professionals manage and monitor the following risks:

* Commodity and currency risk:

* Credit and country risk

We automatically and systemically cover this kind of risk by transferring and using the instruments offered by insurance companies or banks; for example: Stand By Letter of Credit, bank guarantee,…

**Values:**

The key assets of our company and partners on board are our values, which have been constantly our driver:

* **Integrity**, being part of our genetic: we act Honestly and Fairness in all we do

* **Respect**, being our priority: we trust and respect people with whom we are dealing with.

* **Entrepreneurship and team-work**, being our motivation: we are working better together, and we are taking ALL benefit from it

* **Client and Supplier oriented**, being all involved by the result: when our customers and suppliers are happy, this is our gift….Each of us  takes the responsibility for the quality to anything we make.
              |js}
            |> md
          )
        </p>
      </main>
      <main />
    </section>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
