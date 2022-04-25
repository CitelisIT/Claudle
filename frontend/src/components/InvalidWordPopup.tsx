import { Dialog, Popover, Transition } from "@headlessui/react";
import { QuestionMarkCircleIcon, XIcon } from "@heroicons/react/outline";


interface Props {
    badWord: boolean;
    setBadWord:  React.Dispatch<React.SetStateAction<boolean>>;
}

export default function InvalidWordPopup({
    badWord,setBadWord
}: Props) {
  return (
    <Dialog
    open = {badWord}
    onClose={() => setBadWord(false)}
    >
          <Dialog.Title  className="fixed m-auto items-center justify-center gap-4 bg-gray-100 border border-gray-600 rounded-lg top-20 left-4 right-4 md:w-3/12">
            <div className="flex justify-center w-auto items-center">
              <h2 className="text-base items-center font-semibold text-slate-700 md:text-lg lg:text-xl">
                Invalid word
              </h2>
            </div>
        </Dialog.Title>
    </Dialog>
  );
}
